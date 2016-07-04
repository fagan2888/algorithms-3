#include<iostream>
#include<memory>

namespace algorithms {

template<typename T> class node 
{
    template<typename T2> friend class linkedList;
    public:
        node(const T& data) : m_next(nullptr), m_data(data)
        {
            
            m_id++;
#ifdef DEBUG
            std::cout << "Constructing Node " << m_id << std::endl;
#endif 
        }
        
        const node* next() const
        {
            return m_next.get();
        }
        
        T data() const{
            return m_data;
        }
        
        node(node &&) = delete;
        
        ~node() {
#ifdef DEBUG
            std::cout << "Destructing Node " << m_id << std::endl;
#endif
            --m_id;
        }        
        
    private:
        T m_data;
        std::unique_ptr<node<T>> m_next;
        static unsigned int m_id;
};

template<typename T> class linkedList
{
    public:
        linkedList() : m_head(nullptr), m_last(nullptr), m_length(0) {
#ifdef DEBUG
            std::cout << "Constructing Linked List" << std::endl;
#endif 
        };

        ~linkedList() {
#ifdef DEBUG
            std::cout << "Deconstructing Linked List" << std::endl;
#endif 
        };

        linkedList(linkedList&&) = delete;
    
        template<typename T2> friend std::ostream& operator <<(std::ostream& ss, const linkedList<T2>& L);

        void add(const T& data)
        {
            if(m_head == nullptr) 
            {
                m_head = std::make_unique<node<T>>(data);
                m_last = m_head.get();
            }
            else
            {
                m_last->m_next = std::make_unique<node<T>>(data);
                m_last = m_last->m_next.get();
            }
            ++m_length;
        }

        void push(const T& data) 
        {
            if(m_head != nullptr)
            {
                std::unique_ptr<node<T>> tmp = std::make_unique<node<T>>(data);
                tmp->m_next = std::move(m_head);
                std::swap(m_head, tmp);
            }
            else
            {
                m_head = std::make_unique<node<T>>(data); 
            }   
            ++m_length;
        }

        void insert(const T& data, unsigned int position) 
        {
            if(position > m_length)
                throw(std::range_error(std::string("Position index longer than current list length")));

            if(position == 0)
            {
                push(data);
            }
            else if(position == m_length)
            {
                add(data);
            }
            else 
            {
                node<T>* n = m_head.get();
                node<T>* m = nullptr;

                unsigned int i = 1;
                while(n != nullptr)
                {

                    ++i;
                    if(i == position)
                    {
                        std::unique_ptr<node<T>> tmp = std::make_unique<node<T>>(data);
                        tmp->m_next = std::move(m->m_next);
                        //n->m_next = std::move(tmp);
                        break;

                    }
                    n = n->m_next.get();
                }
            }
        }

        unsigned int length()
        {
            return m_length;
        }

        

    private:
        std::unique_ptr<node<T>> m_head;
        node<T>* m_last;
        unsigned int m_length;
};
 
template<typename T>unsigned int node<T>::m_id = 0;

template<typename T>std::ostream& operator <<(std::ostream& ss, const linkedList<T>& L)
{
    const node<T>* n = L.m_head.get();

    if(n == nullptr)
        ss << "Empty List" << std::endl;

    while (n != nullptr)
    {
        ss << n->data() << std::endl ;
        n = n->next();
    }
}

}


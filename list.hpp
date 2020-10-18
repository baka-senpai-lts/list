#pragma once


template<class T>
class List
{
    template<class TT>
    class Node
    {
    public:
        TT value;
        Node<TT>* next;


        Node()
        {
            next = nullptr;
        }


        Node(TT _value) : Node()
        {
            value = _value;
        }


        Node(Node* _next)
        {
            next = _next;
        }


        Node(TT _value, Node* _next)
        {
            value = _value;
            next = _next;
        }
    };


    private:
        Node<T>* first;
        Node<T>* last;
        unsigned int _length;


        Node<T>* get_recursive(Node<T>* current_element, unsigned int n)
        {
            if(n == 0)
        {
            return current_element;
        }

        return get_recursive(current_element -> next, n - 1);
    }


public:
    List()
    {
        last = new Node<T>();
        first = new Node<T>(last);
        _length = 0;
    }


    List(Node<T>* _first, int __length)
    {
        last = new Node<T>();
        first = _first;
        _length = __length;
    }


    List(List<T>* list)
    {
        first = list -> first;
        last = list -> last;
        _length = list -> _length;
    }


    T& head()
    {
        return first -> value;
    }


    List<T> tail()
    {
        return _length > 0 ? List(first -> next, _length - 1) : List(*this);
    }


    List<T>* copy()
    {
        List<T>* list = new List();

        for(int i = 0; i < _length; i++)
        {
            list -> append(get_recursive(first, i) -> value);
        }

        return list;
    }


    void clear()
    {
        while(_length > 0)
        {
            Node<T>* buf = first;
            first = first -> next;
            delete buf;
            _length--;
        }
        
        last = new Node<int>();
        first = new Node<int>(last);
    }


    void append(T value)
    {
        if(_length == 0)
        {
            first -> value = value;
        }
        else
        {
            last -> value = value;
            last -> next = new Node<T>();
            last = last -> next;
        }

        _length++;
    }


    T pop(unsigned int index)
    {
        Node<T>* buf = get_recursive(first, index);

        if(!index)
        {
            first = first -> next;
        }
        else
        {
            get_recursive(first, index - 1) -> next = get_recursive(first, index + 1);
        }

        T result = buf -> value;

        delete buf;

        _length--;

        return result;
    }


    int length()
    {
        return _length;
    }


    T& operator[](unsigned int index)
    {
        if(index < _length)
        {
            return get_recursive(first, index) -> value;
        }

        throw "Out of bounds";
    }
};


template<class T>
void map(List<T> list, T (*function) (T))
{
    list.head() = ((*function) (list.head()));

    if(list.length() > 1) map(list.tail(), function);
}


template<class T>
List<T>* mapf(List<T> list, T (*function) (T))
{
    List<T>* new_list = new List<T>(list.copy());
    map(*new_list, function);
    return new_list;
}


template<class T>
void filter(List<T>& list, bool (*function) (T))
{
    for(int i = 0; i < list.length(); i++)
    {
        if(!(*function)((list)[i]))
        {
            list.pop(i);
            i--;
        }
    }
}


template<class T>
List<T>* filterf(List<T> list, bool (*function) (T))
{
    List<T>* new_list = new List<T>(list.copy());
    filter(*new_list, function);
    return new_list;
}
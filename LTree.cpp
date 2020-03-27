#include <bits/stdc++.h>


#define dbs(i) std::cout<<"lol"<<i<<"\n"


namespace ksb{
    int c = 0;
    int cc = 0;
    int dd = 0;
    template<typename T>
    class LTree
    {
        class _list
        {
        public:
            LTree<T> *_st;
            LTree<T> * __prnt;
            _list *_ft;
            _list *_rr;
            _list(LTree<T> *st = new LTree<T>(),  LTree<T> *prnt=nullptr, _list *ft=nullptr, _list *rr=nullptr): _st(st), _ft(ft), _rr(rr), __prnt(prnt){};
            
        };
        T _dt;
        T _errordt;
        size_t _sz;
        //size_t _ofst;
        std::vector<size_t> _sza;
        //std::vector<size_t> _szb;
        _list *_head;
        _list *_end;
        //_list *_bgn;
        _list *_prnt;
    public:
        // using value_type  = T;
        // using difference_type = unsigned int;
        using value_type        = T;
        using size_type         = size_t;
        using pointer           = value_type*;
        using const_pointer     = const value_type*;
        using reference         = value_type&;
        using const_reference   = const value_type&;

        LTree(size_t n, T dt = T()): _sz(n){
            //_ofst = 1;
            //_bgn = nullptr;
            //dbs(n);
            size_t it = 2;
            _dt = dt;
            if(n > 0)
            {
                 --n;
                _list *tt = nullptr;
                _list *pr = nullptr;
                _prnt = nullptr;
                //dbs(0);
                _end = new _list(new LTree<T>(0, dt), this);
                _end -> _st -> _prnt = _end;
                _head = _end;
                
                //dbs(5);
                if(n>0){
                    size_t ssz = std::min(it, n);
                    //dbs(int(ssz));
                    _head = new _list(new LTree<T>(ssz, dt), this);
                    _head -> _st->_prnt = _head;
                    _head -> _rr = pr;
                    _head -> _ft = _end;
                    _end -> _rr = _head;
                    pr = _head;
                    tt = _head -> _ft;
                    if(it >= n) n = 0;
                    else n = n - it;
                    _sza.push_back(it);
                    it = it * 2;
                }
                while(n>0){
                    size_t ssz = std::min(it, n);
                    tt = new _list(new LTree<T>(ssz, dt), this);
                    tt -> _st->_prnt = tt;
                    tt -> _rr = pr;
                    tt -> _ft = pr -> _ft;
                    pr -> _ft -> _rr = tt;
                    pr -> _ft = tt;
                    //dbs(1);
                    pr = tt;
                    tt = tt -> _ft;
                    if(it >= n) n = 0;
                    else n = n - it;
                    _sza.push_back(it);
                    it = it * 2;
                }
                //dbs(2);
            }
        };

        class iterator : public std::iterator<std::random_access_iterator_tag, T, long int, T*, T&>
        {
            LTree<T> *_ptr;
        public:
            // using value_type        = T;
            // using size_type         = size_t;
            // using difference_type   = ptrdiff_t;
            // using pointer           = value_type*;
            // using const_pointer     = const value_type*;
            // using reference         = value_type&;
            // using const_reference   = const value_type&;
            iterator(LTree<T> *ptr=nullptr): _ptr(ptr){};
            
            iterator operator++(){
                //dbs(0);
                if(_ptr -> _head != _ptr -> _end){
                    _ptr = (_ptr -> _head->_st);
                    return *this;
                }
                else if(_ptr -> _prnt != nullptr){
                    //std::cerr<<"lol\n";
                    _list *prnt = _ptr -> _prnt;
                    //std::cerr<<"lol2\n";
                    //dbs(1);
                    while(prnt!=nullptr && prnt -> _ft == prnt -> __prnt -> _end) {
                        _ptr = prnt -> __prnt -> _end -> _st;
                    //std::cerr<<"lol0  "<<(prnt->__prnt == nullptr)<<"\n";
                        prnt = prnt -> __prnt -> _prnt;
                    }
                    // dbs(2);
                    //std::cerr<<"lol3\n";
                    if(prnt != nullptr){
                        //std::cerr<<(prnt -> _ft == nullptr)<<" lol4\n";
                        _ptr = (prnt -> _ft -> _st);
                       // std::cerr<<(_ptr -> _dt)<<" lol5\n";
                    }

                    //std::cerr<<"lol6\n";
                    return *this;
                }
                else{
                    //dbs(4);
                    _ptr = _ptr -> _end -> _st;
                    return *this;
                }
                this -> _ptr = nullptr;
                return *this;
            }

            iterator operator++(int){
                auto tmp = *this;
                ++*this;
                return tmp;
            }

            iterator operator--(){
                //dbs(3);
                if(_ptr -> _prnt == nullptr){ 
                    _ptr = nullptr;
                    return *this;
                }
                else{
                    _list *prnt = _ptr -> _prnt;
                    //dbs(6);
                    if(prnt -> _rr == nullptr){
                        _ptr = prnt -> __prnt;
                        return *this;
                    }
                    else{
                        prnt = prnt -> _rr;
                        while(prnt -> _st -> _end -> _rr != nullptr){
                            prnt = prnt -> _st -> _end -> _rr;
                        }
                        _ptr = prnt -> _st;
                        return *this;
                    }
                }
                _ptr = nullptr;
                return *this;
            }
            iterator operator--(int){
                auto tmp = *this;
                --*this;
                return tmp;
            }

            iterator operator+(unsigned int inc){
                //dbs(1);
                ++cc;
                dd = std::max(cc,dd);
                if(inc == 0) return *this;
                if(inc == 1) {
                    auto tmp = *this;
                    ++tmp;
                    return tmp;
                }
                if(_ptr -> _sz >= inc){
                    auto tt = _ptr -> _head;
                    unsigned int itr = 0;
                    while(tt!=nullptr)
                    {
                        if(inc <= _ptr->_sza[itr]){
                            //dbs(1);
                            return tt -> _st -> begin() + (inc - 1);
                        }
                        tt = tt -> _ft;
                        inc = inc - _ptr->_sza[itr];
                        ++itr;
                    }
                    return iterator(nullptr);
                }
                inc = inc - (_ptr -> _sz - 1);
                if(_ptr -> _prnt != nullptr){
                    if(_ptr -> _prnt -> _ft != nullptr){
                        return _ptr -> _prnt -> _ft -> _st -> begin() + (inc - 1); 
                    }
                    _ptr = _ptr -> _prnt -> __prnt;
                    return _ptr -> begin() + (_ptr -> _sz + inc - 1);
                }

                return iterator(nullptr);
            }


            iterator operator-(unsigned int dec){
                //dbs(dec);
                if(dec == 0) return *this;
                if(dec == 1) {
                    auto tmp = *this;
                    --tmp;
                    return tmp;
                }
                if(_ptr->_prnt != nullptr){
                    if(_ptr->_prnt -> _rr !=nullptr){
                        _list *tt = _ptr->_prnt -> _rr;
                        //dbs(dec);
                        //dbs((tt -> _st ->_sz));
                        if(dec <= tt -> _st ->_sz){
                            dec = tt -> _st ->_sz - dec;

                            return tt -> _st -> begin() + dec;
                        }
                        //dbs(0);
                        dec = dec -  tt -> _st ->_sz;

                        return tt -> _st -> begin() - dec;
                    }
                    //dbs(100);
                    return _ptr->_prnt->__prnt->begin() - (dec - 1);
                }
                return iterator(nullptr);
            }


            // Temporary implementation ..... Have to come with an idea and change this
            unsigned int operator-(const iterator &x){
                auto tmp = *this;
                unsigned int n = 0;
                while(tmp._ptr != x._ptr){
                    //dbs(0);
                    --tmp;
                    ++n;
                }
                return n;
            }

            bool operator<(const iterator &x){
                auto tmp = *this;
                while(tmp._ptr != x._ptr && tmp._ptr != nullptr){
                    --tmp;
                }
                if(tmp == nullptr) return true;
                return false;

            }

            bool operator<=(const iterator &x){
                return this -> operator<(x) || this -> operator==(x);
            }

            bool operator>(const iterator &x){
                auto tmp = *this;
                while(tmp._ptr != x._ptr && tmp._ptr != nullptr){
                    --tmp;
                }
                if(tmp == nullptr) return false;
                return true;

            }

            bool operator>=(const iterator &x){
                return this -> operator>(x) || this -> operator==(x);
            }

            T &operator*(){
                return _ptr->_dt;
            }

            bool operator==(const iterator &a){
                return a._ptr == _ptr;
            }

            bool operator!=(const iterator &a){
                return !this->operator==(a);
            }

            
        };


        iterator begin(){
            return iterator(this);
        }
        iterator end(){
            return iterator(_end->_st);
        }


        T &operator[](unsigned int idx){
            if(idx == 0)
                return _dt;
            _list *tt = _head;
            _list *tp = tt;
            --idx;
            //dbs(1);
            int itr = 0;
            while(tt != _end){
                if(idx < _sza[itr]){
                    //dbs(1);
                    return tt -> _st -> operator[](idx);
                }
                idx = idx - _sza[itr];
                ++itr;
                tt = tt -> _ft;
            }
            
            return _errordt;
        }

        void printData(){
            for(int i = 0 ; i < c; ++i) std::cout<<" ";
            std::cout<<_dt<<"\n";
            _list * tt = _head;
            while(tt != nullptr){
                //std::cerr<<"lol\n";
                c++;
                tt->_st->printData();
                c--;
                tt = tt->_ft;
            }
        }
    };
}




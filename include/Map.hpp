#ifndef MAP_HPP
# define MAP_HPP

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>,
        	class Alloc = std::allocator<pair<const Key,T> > >
	class map
	{
		private:
			typedef	Key									key_type;
			typedef	T									mapped_type;
			typedef pair<const key_type, mapped_type>	value_type;
			typedef Compare								key_compare;
			class 	value_compare;
			
			typedef Alloc								allocator_type;
			typedef typename Alloc::reference			reference;
			typedef typename Alloc::const_reference		const_reference;
			typedef typename Alloc::pointer				pointer;
			typedef typename Alloc::const_pointer		const_pointer;
			typedef Iterator<const Key, T, key_compare> 			iterator;
			typedef Iterator<const Key, const T, key_compare>	const_iterator;
			typedef ReverseIterator<iterator>			reverse_iterator;
			typedef ReverseIterator<const_iterator>	const_reverse_iterator;
			typedef std::ptrdiff_t						difference_type;
			typedef size_t								size_type;
		public:
			explicit map(const key_compare& comp = key_compare(),
            	const allocator_type& alloc = allocator_type());
			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type());
			map(const map& x);
			~map();
			map& operator= (const map& x);

			iterator				begin(void);
			const_iterator			begin(void) const;
			iterator				end(void);
			const_iterator			end(void) const;
			reverse_iterator		rbegin(void);
			const_reverse_iterator	rbegin() const;
			reverse_iterator		rend(void);
			const_reverse_iterator	end() const;

			bool		empty(void) const;
			size_type	size(void) const;
			size_type	max_size(void) const;

			mapped_type&	operator[] (const key_type& k);

			pair<iterator,bool> insert(const value_type& val);
			iterator insert(iterator position, const value_type& val);
			template <class InputIterator>
			void insert(InputIterator first, InputIterator last);
			void erase(iterator position);
			size_type erase(const key_type& k);
			void erase(iterator first, iterator last);
			void swap(map& x);
			void clear();

			key_compare key_comp() const;
			value_compare value_comp() const;

			iterator find (const key_type& k);
			const_iterator find (const key_type& k) const;
			size_type count (const key_type& k) const;
			iterator lower_bound (const key_type& k);
			const_iterator lower_bound (const key_type& k) const;
			iterator upper_bound (const key_type& k);
			const_iterator upper_bound (const key_type& k) const;
			pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
			pair<iterator,iterator>             equal_range (const key_type& k);
	};

}

#endif
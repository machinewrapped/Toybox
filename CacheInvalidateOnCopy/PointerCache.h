#pragma once
#include <vector>
#include <algorithm>

template <typename T>
class PointerCache
{
public:
	PointerCache()
	{
		Invalidate();
	}

	PointerCache(const PointerCache& rhs)					
	{ 
		Invalidate(); 
	}
	
	PointerCache& operator=(const PointerCache& rhs) 
	{ 
		Invalidate(); 
		return *this; 
	}

	void PushBack(T& item) 
	{ 
		m_pointers.push_back(&item);
	}

	bool Size() { return m_pointers.size(); }
	bool Empty() { return m_pointers.empty(); }
	void Clear() { Invalidate(); }

	using container = std::vector<T*>;
	using iterator = typename container::iterator;
	using const_iterator = typename container::const_iterator;

	iterator begin() { return m_pointers.begin(); }
	iterator end() { return m_pointers.end(); }

	const_iterator cbegin() const { return m_pointers.cbegin(); }
	const_iterator cend() const { return m_pointers.cend(); }

private:
	container m_pointers;

	void Invalidate()
	{
		m_pointers.clear();
	}
};


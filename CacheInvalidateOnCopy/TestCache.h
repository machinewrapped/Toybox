#pragma once

#include "PointerCache.h"
#include <string>

class TestCache
{
public:
	TestCache(const char* a, const char* b, const char* c)
		: m_one(a)
		, m_two(b)
		, m_three(c)
	{
		InitialiseCache();
	}

	auto begin() 
	{ 
		UpdateCache(); 
		return m_cache.begin(); 
	}

	auto end() 
	{ 
		UpdateCache(); 
		return m_cache.end(); 
	}

private:
	std::string m_one;
	std::string m_two;
	std::string m_three;

	PointerCache<std::string> m_cache;

	void InitialiseCache()
	{
		m_cache.PushBack(m_one);
		m_cache.PushBack(m_two);
		m_cache.PushBack(m_three);
	}

	void UpdateCache()
	{
		if (m_cache.Empty())
		{
			InitialiseCache();
		}
	}
};


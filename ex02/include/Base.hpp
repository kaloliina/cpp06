#pragma once

class Base
{
	public:
	virtual ~Base() = default;

	Base*	generate(void);
	void	identify(Base* p);
	void	identify(Base& p);
};


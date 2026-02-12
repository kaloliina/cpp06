#pragma once

class Base
{
	public:
	virtual ~Base() = default;

	void	identify(Base* p);
	void	identify(Base& p);
};
	Base*	generate(void);

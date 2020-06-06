std:: ostream& operator<<(std::ostream &F, X const& arg)
{
	return F << arg;
};

Błędem w powyższym zapisie jest wartość zwraca przez funkcję nadpisującą operator:
powinno to wyglądać:

	return F << arg._x;

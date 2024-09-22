#include "Serializer.hpp"

int	main(void)
{

	Data *data = new Data;
	data->str = "yturgut";
	data->i = 11;
	std::cout <<"Data adress: "<<data<<std::endl;
	std::cout <<"Value of str: "<<data->str<<std::endl;
	std::cout<<"Value of val: "<<data->i<<std::endl;
	uintptr_t i = Serializer::serialize(data);

	Data *d = Serializer::deserialize(i);
	if(d == data)
		std::cout<<"They're equal\n";
	std::cout <<"d -> "<< &d <<std::endl;
	std::cout<<"i -> "<< i <<std::endl;

	std::cout <<"Data adress: "<<d<<std::endl;
	std::cout <<"Value of str: "<<d->str<<std::endl;
	std::cout<<"Value of val: "<<d->i<<std::endl;
	d->i = 25;
	std::cout<<"Value of val: "<<d->i<<std::endl;
	std::cout<<"Value of val: "<<data->i<<std::endl;
	delete data;
	return (0);
}
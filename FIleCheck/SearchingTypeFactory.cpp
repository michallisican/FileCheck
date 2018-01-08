#include "iSearchingType.h"
#include "SearchingTypeParallel.h"
#include "SearchingTypeSequential.h"
#include "SearchingTypeFactory.h"


std::shared_ptr<iSearchingType> SearchingTypeFactory::SearchType(int methode, int type)
{
	if (type == parallel_t)
		return std::make_shared<SearchingTypeParallel>(methode, type);
	else if (type == sequential_t )
		return std::make_shared<SearchingTypeSequential>(methode, type);
	else
	{
		throw std::exception("SearchingFactory::SearchType: type not found!!!\n");
		return nullptr;
	}
}

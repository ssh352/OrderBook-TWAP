#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm> // copy

#include "MarketDataProvider.h"
#include "Utils.h"

void trading::MarketDataProvider::readMarketDataFile(const std::string& filename)
{
	messages_.clear();
	filename_ = filename;
	messages_ = readFile2Vector(filename_);
	std::cout << "MarketDataProvider is initialized with " << messages_.size() << " messages" << std::endl;
	cur_ = trading::MarketDataProvider::messages_.begin();
}

bool trading::MarketDataProvider::hasNextMessage()
{
	return (cur_ != messages_.end());
}

const std::string& trading::MarketDataProvider::nextMessage()
{
	if (hasNextMessage())
    {
		std::vector<std::string>::iterator saved = cur_;
		cur_++;
		return *saved;
	}
	else
	{
		throw(trading::OutOfBounds());
	}
}
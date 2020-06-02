#include "Application.h"

int main(int argc, char* argv[])
{
	std::unique_ptr<Application> launcher = std::make_unique<Application>();

	launcher->run();

	return 0;
}
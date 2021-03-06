#include "main.h"
#include "../../Common/CompilerSettings.h"

#include "../../Client/NM_Engine/NM_Index.h"
#ifdef _DEBUG
	#pragma comment(lib, "../../Bin/Debug/NM_Engine.lib")
#else
	#pragma comment(lib, "../../Bin/Release/NM_Engine.lib")
#endif

#include <xorstr.hpp>
#include <lazy_importer.hpp>

#define NM_MASTER_SERVER_PORT 1881


int main()
{
	auto nmCommon = std::make_unique<CNoMercy>();
	if (!nmCommon || !nmCommon.get())
	{
		printf(xorstr("NoMercy class can NOT created! Last error: %u\n").crypt_get(), LI_FIND(GetLastError)());
		return EXIT_FAILURE;
	}

	nmCommon->InitMasterServer(NM_MASTER_SERVER_PORT); // TODO: Get port order with stdin from config json and send it instead of pre defined port(1881)

#ifdef _DEBUG
	printf(" # COMPLETED! # \n");
#endif

	while (1) LI_FIND(Sleep)(1000);

	return EXIT_SUCCESS;
}


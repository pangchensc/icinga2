/* Icinga 2 | (c) 2012 Icinga GmbH | GPLv2+ */

#ifndef VARIABLEQUERYHANDLER_H
#define VARIABLEQUERYHANDLER_H

#include "remote/httphandler.hpp"

namespace icinga
{

class VariableQueryHandler final : public HttpHandler
{
public:
	DECLARE_PTR_TYPEDEFS(VariableQueryHandler);

	bool HandleRequest(const ApiUser::Ptr& user, HttpRequest& request,
		HttpResponse& response, const Dictionary::Ptr& params) override;
};

}

#endif /* VARIABLEQUERYHANDLER_H */

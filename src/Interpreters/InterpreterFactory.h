#pragma once

#include <Core/QueryProcessingStage.h>
#include <Interpreters/IInterpreter.h>
#include <Interpreters/SelectQueryOptions.h>
#include <Parsers/IAST_fwd.h>


namespace DB
{

class Context;

class InterpreterFactory : private boost::noncopyable
{
public:
    static InterpreterFactory & instance();
    static std::unique_ptr<IInterpreter> get(
        ASTPtr & query,
        ContextMutablePtr context,
        const SelectQueryOptions & options = {});
};

}

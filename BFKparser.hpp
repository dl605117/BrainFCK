#pragma once

namespace script {

    class Environment {
    public:
        Environment();
        ~Environment();
        int *curPointer();
        void incPointer();
        void decPointer();
    private:
        long memSize;
        void *envMem;
    }

    class Command {
    public:
        virtual void execute(Environment &e) = 0;
    }

    enum DataOpType {
        IncP, DecP, IncD, DecD, OutD, AccD
    };

    class DataOp : public Command {
    public:
        const DataOpType type;
    }

    class Loop : public Command {
    public:
        Command cmdThis;
        Command cmdNext;
    }

}
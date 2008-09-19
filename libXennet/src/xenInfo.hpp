#ifndef XENINFO_HPP
#define XENINFO_HPP

#include "xenMain.hpp"

//! The Xennet namespace.
/*!
    The Xennet namespace contains all of the classes and functions in the library.
*/
namespace Xennet
{
    //! The Info class provides library information
    class Info
    {
    public:
        /*! Default constructor */
        Info();
        /*! Default destructor */
        virtual ~Info();
        //! Get Xennet library version
        static std::string getVersion();
        //! Get library description
        static std::string getDescription();
        //! Get the copyright/license for the Xennet library
        static std::string getCopyright();
    protected:
    private:
    };

} // namespace Xennet

#endif // XENINFO_HPP

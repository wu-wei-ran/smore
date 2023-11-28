#ifndef STT_COMMON_H
#define STT_COMMON_H
#include <string>
namespace smartmore
{ // namespace of smartmore

    //!
    //! \enum ResultCode
    //!
    enum class ResultCode
    {
        Success = 0,

        NotInited = 10001,
        BadModel = 10101,
        BadInput = 10102,
        NotImage = 10103,
        NotVideo = 10104,

        InternalError = 20001,
        OutOfMemory = 20002,
        CudaError = 20003,

        NoLicense = 30000,
        CallLimited = 30001,
        LicenseExpired = 30002,
        WrongAppName = 30003,
    };

} // namespace smartmore

#endif

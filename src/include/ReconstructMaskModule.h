#ifndef RECONSTRUCTMASKMODULE_H
#define RECONSTRUCTMASKMODULE_H

#include "Common.h"
#include "ModuleTypes.h"

#include <memory.h>

namespace smartmore {

class ReconstructMaskModule
{
public:
    ReconstructMaskModule();
    ~ReconstructMaskModule();

    //!
    //! \brief Init ReconstructMaskModule with given model path.
    //!
    //! \param model_path The path of input model.
    //! \param use_gpu Whether use gpu in subsequent inference.
    //! \param device_id ID of gpu used.(-1 for auto choose, default device 0)
    //!
    //! \return The status of Initialization. OK for success, else non-zero.
    //!
    //! In particular, this function is called prior to any call to Run().
    //!
    ResultCode Init(const std::string &model_path, bool use_gpu, int device_id);

    //!
    //! \brief Do inference.
    //!
    //! \param req The origin request.
    //! \param rsp The response generated from Run.
    //!
    //! \return The status of Inference. OK for success, else non-zero.
    //!
    ResultCode run(const Segment_Request &req, Segment_Response &rsp);

private:
    class ReconstructMaskModuleImpl;

    std::unique_ptr<ReconstructMaskModuleImpl> impl_;
private:

};

}

#endif
#include "DetectModule.h"

#include <fstream>
#include <vector>

using namespace smartmore;

namespace
{
    std::vector<unsigned char> readBufferFromONNX(const std::string &model_path)
    {
        std::ifstream fs;
        fs.open(model_path, std::ios::binary | std::ios::in);
        if (!fs.is_open())
        {
            char info[512];
            sprintf(info, "read model file %s failed !\n", model_path.c_str());
            throw std::runtime_error(info);
        }
        fs.seekg(0, std::ios::end);
        long length = fs.tellg();
        fs.seekg(0, std::ios::beg);
        std::vector<unsigned char> modelData(length);
        fs.read(reinterpret_cast<char *>(modelData.data()), length);
        fs.close();

        return modelData;
    }
} // namespace

class DetectModule::DetectModuleImpl
{
public:
    DetectModuleImpl() = default;
    ~DetectModuleImpl() = default;
    ResultCode Init(const std::string &model_path, bool use_gpu, int device_id)
    {

        return ResultCode::Success;
    }

    ResultCode run(const Detect_Request &req, Detect_Response &rsp)
    {

        return ResultCode::Success;
    }

private:
    const std::vector<std::string> class_names = {
        "pedestrian", "car", "bus", "truck", "bicycle", "mobike", "tricycle"};
};

DetectModule::DetectModule() : impl_(std::make_unique<DetectModuleImpl>())
{
}

DetectModule::~DetectModule()
{
}

ResultCode DetectModule::Init(const std::string &model_path, bool use_gpu, int device_id)
{
    return impl_->Init(model_path, use_gpu, device_id);
}

ResultCode DetectModule::run(const Detect_Request &req, Detect_Response &rsp)
{
    return impl_->run(req, rsp);
}

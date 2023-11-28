#include "ReconstructMaskModule.h"

#include <fstream>
#include <iostream>
#include <vector>

namespace smartmore
{
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

    class ReconstructMaskModule::ReconstructMaskModuleImpl
    {
    public:
        ReconstructMaskModuleImpl() = default;
        ~ReconstructMaskModuleImpl() = default;

        ResultCode Init(const std::string &model_path, bool use_gpu, int device_id)
        {
            std::cout << "init";

            return ResultCode::Success;
        }

        ResultCode run(const Segment_Request &req, Segment_Response &rsp)
        {

            // 增加后处理
            return ResultCode::Success;
        }
    };

    ReconstructMaskModule::ReconstructMaskModule() : impl_(std::make_unique<ReconstructMaskModuleImpl>()) {}

    ReconstructMaskModule::~ReconstructMaskModule() {}

    ResultCode ReconstructMaskModule::Init(const std::string &model_path, bool use_gpu, int device_id)
    {
        return impl_->Init(model_path, use_gpu, device_id);
    }

    ResultCode ReconstructMaskModule::run(const Segment_Request &req, Segment_Response &rsp)
    {
        return impl_->run(req, rsp);
    }
} // namespace smartmore

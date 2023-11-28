#ifndef MODULETYPES_H
#define MODULETYPES_H

#include <string>
#include <vector>

namespace smartmore
{

    //!
    //! \struct Box coordinate of detected object
    //! \param xmin
    //! \param xmax
    //! \param ymin
    //! \param ymax
    //!
    struct Box
    {
        float xmin, ymin, xmax, ymax;
    };

    //!
    //! \struct DetectedObj
    //! \param bbox
    //! \param score
    //! \param label
    //! \param class_id
    //! \param track_id
    //!
    struct DetectedObj
    {
        Box box;
        float score;
        std::string label;
        int class_id = -1;
        long long track_id = -1;
    };

    //!
    //! \struct Detect_Request
    //! \param image
    //!
    struct Detect_Request
    {
    };

    //!
    //! \struct Detect_Response
    //! \param objs results from detection model
    //!
    struct Detect_Response
    {
        std::vector<DetectedObj> objs;
    };

    //!
    //! \struct Segment_Request
    //! \param image
    //!
    struct Segment_Request
    {
    };

    //!
    //! \struct Segment_Response
    //! \param image
    //!
    struct Segment_Response
    {
    };

} // namespace smartmore

#endif

//
// created by caishuai on 12-24-2018
//
#pragma once

#include <unistd.h>
#include <fcntl.h>
#include <google/protobuf/text_format.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>

#include "protos/calibration.pb.h"

bool ReadConfig(const std::string &config_file, calibration::Config &config)
{
    using google::protobuf::TextFormat;
    using google::protobuf::io::FileInputStream;
    using google::protobuf::io::ZeroCopyInputStream;
    int file_descriptor = open(config_file.c_str(), O_RDONLY);
    if (file_descriptor < 0)
    {
        std::cout << "Failed to open file " << config_file << " in text mode." << std::endl;
        return false;
    }

    ZeroCopyInputStream *input = new FileInputStream(file_descriptor);
    bool success = TextFormat::Parse(input, &config);
    if (!success)
    {
        std::cout << "Failed to parse file " << config_file << " as text proto." << std::endl;
        return false;
    }

    delete input;
    close(file_descriptor);

    return true;
}

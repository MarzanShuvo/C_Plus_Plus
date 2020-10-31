#include "igg_image/io_strategies/ppm_strategy.h"
#include<string>


namespace igg{

    bool PpmIoStrategy::Write(const std::string& file_name, const ImageData& data) const{
        std::ofstream create_image(file_name);

        create_image<<"P3"<<std::endl;
        create_image<<data.rows<<" "<< data.cols<<std::endl;
        create_image<<data.max_val<<std::endl;

        for(int i=0; i<data.rows; i++){
            for(int j=0; j<data.cols; j++){
                int index = data.rows*i+j;
                create_image<<data.data[0][index]<<" "<<data.data[1][index]<<" "<< data.data[2][index]<<"\t";
                if(j==data.cols-1){
                    create_image<<""<<std::endl;
                }
            }
        }
        return true;


    }

    ImageData PpmIoStrategy::Read(const std::string& file_name) const{
        //copied code...
        // Start file reader
        std::ifstream input(file_name, std::ios_base::in);

        // Create ImageData structure and the red, green and blue vectors
        ImageData image;
        image.cols=0;
        image.rows=0;
        image.max_val=0;

        // Read the header
        std::string line;
        bool read_first = false;
        bool read_second = false;
        bool read_third = false;
        while(!read_third) {
        std::getline(input, line);

        // Check if first line
        if (line[0] == 'P') {read_first = true; continue;}
        // Check if comment
        if (line[0] == '#') continue;
        // Check if second line
        if (read_first && !read_second) {
            std::stringstream ss(line);
            ss >> image.rows >> image.cols;
            read_second = true;
            continue;
        }
        if (read_second) {
            std::stringstream ss(line);
            ss >> image.max_val;
            read_third = true;
        }
        }

        // Values
        std::vector<int> red(image.rows * image.cols, 0);
        std::vector<int> green(image.rows * image.cols, 0);
        std::vector<int> blue(image.rows * image.cols, 0);

        // Read values
        int cols = image.cols;
        int r = 0;
        int c = 0;
        while(std::getline(input, line)) {
        std::stringstream ss(line);

        // I think there has to be a better solution
        int idx = r * cols + c;
        while (ss >> red[idx] >> green[idx] >> blue[idx]) {
            if (++c == cols) {
            r++;
            c = 0;
            }
            idx = r * cols + c;
        }
        }
        image.data = {red, green, blue};
        return image;
    }
}
#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"

#include "MyFilter.h"


int main(int argc, char*argv[])
{
    
    if( argc < 3 )
    {
        std::cerr << "Usage: " << std::endl;
        std::cerr << argv[0] << "   inputImageFile " << std::endl;
        return EXIT_FAILURE;
    }
    else
    {
        // Setup types
        typedef itk::Image<unsigned char, 2>   ImageType;
        typedef itk::MyFilter<ImageType>  FilterType;
    
        // Load the Input Image
        typedef itk::ImageFileReader< ImageType >  ReaderType;
        ReaderType::Pointer reader = ReaderType::New();
        const char * filename = argv[1];
        reader->SetFileName( filename );
        
        try
        {
            reader->Update();
        }
        catch ( itk::ExceptionObject &err)
        {
            std::cerr << "ExceptionObject caught !" << std::endl;
            std::cerr << err << std::endl;
            return EXIT_FAILURE;
        }
        
        ImageType::Pointer image = reader->GetOutput();
    

        
    
        /** Treatment */
        FilterType::Pointer filter=FilterType::New();
        filter->SetInput(image);
        filter->Update();
        
    
        // Write the Output Image
        typedef  itk::ImageFileWriter< ImageType > WriterType;
        WriterType::Pointer writer = WriterType::New();
        
        const char * outputFilename = argv[2];
        writer->SetFileName(outputFilename);
        writer->SetInput(filter->GetOutput());
        
        try
        {
            writer->Update();
        }
        catch ( itk::ExceptionObject &err)
        {
            std::cerr << "ExceptionObject caught !" << std::endl;
            std::cerr << err << std::endl;
            return EXIT_FAILURE;
        }
        
        return EXIT_SUCCESS;
    }

    
}


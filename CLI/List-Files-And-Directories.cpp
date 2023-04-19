#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <map>

std::string get_permissions(const std::filesystem::path& path) {
    std::string permissions;
    std::filesystem::perms perms = std::filesystem::status(path).permissions();
    permissions += ((perms & std::filesystem::perms::owner_read) != std::filesystem::perms::none) ? "r" : "-";
    permissions += ((perms & std::filesystem::perms::owner_write) != std::filesystem::perms::none) ? "w" : "-";
    permissions += ((perms & std::filesystem::perms::owner_exec) != std::filesystem::perms::none) ? "x" : "-";
    permissions += ((perms & std::filesystem::perms::group_read) != std::filesystem::perms::none) ? "r" : "-";
    permissions += ((perms & std::filesystem::perms::group_write) != std::filesystem::perms::none) ? "w" : "-";
    permissions += ((perms & std::filesystem::perms::group_exec) != std::filesystem::perms::none) ? "x" : "-";
    permissions += ((perms & std::filesystem::perms::others_read) != std::filesystem::perms::none) ? "r" : "-";
    permissions += ((perms & std::filesystem::perms::others_write) != std::filesystem::perms::none) ? "w" : "-";
    permissions += ((perms & std::filesystem::perms::others_exec) != std::filesystem::perms::none) ? "x" : "-";
    return permissions;
}

int main() {
    // too lazy to add more types to this
    std::map<std::string, std::string> file_types = {
        {".py", "Python"},
        {".cpp", "C++"},
        {".cs", "C#"},
        {".rb", "Ruby"},
        {".png", "Image"},
        {".jpg", "Image"},
        {".mp4", "Video"},
        {".zip", "Archive"},
        {".txt", "Text"},
        {".docx", "Microsoft Word document"},
        {".xlsx", "Microsoft Excel spreadsheet"},
        {".pdf", "PDF document"},
        {".html", "HTML document"},
        {".js", "JavaScript file"},
        {".css", "CSS file"},
        {".java", "Java file"},
        {".php", "PHP file"},
        {".svg", "Scalable Vector Graphics"},
        {".json", "JSON file"},
        {".xml", "XML file"},
        {".csv", "Comma-separated values file"},
        {".pptx", "Microsoft PowerPoint presentation"},
        {".odt", "OpenDocument Text document"},
        {".ods", "OpenDocument Spreadsheet"},
        {".ogg", "Ogg audio file"},
        {".wav", "Waveform Audio File Format"},
        {".midi", "MIDI file"},
        {".3gp", "3GPP multimedia file"},
        {".mp3", "MPEG audio stream, layer III"},
        {".mkv", "Matroska Multimedia Container"},
        {".avi", "Audio Video Interleave file format"},
        {".rar", "RAR archive"},
        {".tgz", "Tar-gzip compressed file"},
    };
    std::filesystem::path path(".");
    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        std::string file_type = std::filesystem::is_directory(entry.path()) ? "Folder" :
            (file_types.count(entry.path().extension().string()) ? file_types[entry.path().extension().string()] : "Undefined");
        std::string permissions = get_permissions(entry.path());
        std::cout << "\033[33m" << entry.path().filename().string() << "\033[0m"
                  << " (" << file_type << ") "
                  << permissions << std::endl;
    }
    return 0;
}

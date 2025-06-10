/*
Problem Statement:
You're building a document editor application (like MS Word or Google Docs).
The app should support saving documents in multiple formats:

.pdf
.docx
.html

You want the ability to:
    Easily add new formats in the future (e.g., .txt, .md)
    Allow the user to choose the export format at runtime
    Keep your code clean and maintainable (no big if-else chains)
*/

/*
Answer:Best Design Pattern: Strategy Pattern
Why Strategy Pattern?
    You need to:
        Define multiple algorithms (PDF export, DOCX export, HTML export)
        Allow the editor to switch export logic at runtime
        Avoid bloating the editor with format-specific logic
*/


#include <iostream>
#include <memory>
class ExportStrategy {
public:
    virtual void exportDocument(const std::string& content) = 0;
    virtual ~ExportStrategy() {}
};

class PDFExport : public ExportStrategy {
public:
    void exportDocument(const std::string& content) override {
        std::cout << "Exporting to PDF: " << content << std::endl;
    }
};

class DOCXExport : public ExportStrategy {
public:
    void exportDocument(const std::string& content) override {
        std::cout << "Exporting to DOCX: " << content << std::endl;
    }
};

class HTMLExport : public ExportStrategy {
public:
    void exportDocument(const std::string& content) override {
        std::cout << "Exporting to HTML: " << content << std::endl;
    }
};

class DocumentEditor {
    std::unique_ptr<ExportStrategy> strategy;
public:
    void setExportStrategy(std::unique_ptr<ExportStrategy> s) {
        strategy = std::move(s);
    }

    void save(const std::string& content) {
        if (strategy)
            strategy->exportDocument(content);
        else
            std::cout << "No export strategy set.\n";
    }
};

int main() {
    DocumentEditor editor;

    editor.setExportStrategy(std::make_unique<PDFExport>());
    editor.save("My report content");

    editor.setExportStrategy(std::make_unique<HTMLExport>());
    editor.save("My report content");

    return 0;
}

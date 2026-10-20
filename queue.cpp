#include <iostream>
#include <string>
#include <queue>

using namespace std;

// Structure to represent a single print job
struct PrintJob {
    int jobId;
    string documentName;
    int pageCount;
};

class PrinterSpooler {
private:
    queue<PrintJob> jobQueue;
    int nextId;

public:
    PrinterSpooler() {
        nextId = 1;
    }

    // Add a new print job to the back of the queue (Enqueue)
    void addJob(string docName, int pages) {
        PrintJob newJob;
        newJob.jobId = nextId++;
        newJob.documentName = docName;
        newJob.pageCount = pages;

        jobQueue.push(newJob);
        cout << "[Added] Job #" << newJob.jobId << ": \"" << newJob.documentName 
             << "\" (" << newJob.pageCount << " pages) placed in queue.\n";
    }

    // Process/Print the job at the front of the queue (Dequeue)
    void processNextJob() {
        if (jobQueue.empty()) {
            cout << "Printer Queue is empty. No jobs to process.\n";
            return;
        }

        PrintJob currentJob = jobQueue.front(); // Get the first item
        jobQueue.pop(); // Remove it from the queue

        cout << "\n[Printing...] Processing Job #" << currentJob.jobId 
             << " (\"" << currentJob.documentName << "\", " 
             << currentJob.pageCount << " pages)...\n";
        cout << "--> Print completed successfully!\n\n";
    }

    // Display all pending jobs currently waiting in the queue
    void displayQueue() {
        if (jobQueue.empty()) {
            cout << "Current Print Queue: [ Empty ]\n";
            return;
        }

        queue<PrintJob> tempQueue = jobQueue; // Copy to display without altering original
        cout << "--- Current Print Queue Status ---\n";
        while (!tempQueue.empty()) {
            PrintJob job = tempQueue.front();
            cout << "  -> Job ID: " << job.jobId 
                 << " | Doc: " << job.documentName 
                 << " | Pages: " << job.pageCount << "\n";
            tempQueue.pop();
        }
        cout << "----------------------------------\n";
    }
};

int main() {
    cout << "=== PRINTER SPOOLER SYSTEM (Queue Demonstration) ===\n\n";
    
    PrinterSpooler spooler;

    // Simulating users sending documents to the printer
    spooler.addJob("Research_Proposal.pdf", 12);
    spooler.addJob("Assignment_Report.docx", 5);
    spooler.addJob("Lecture_Notes.pdf", 25);

    cout << "\n";
    spooler.displayQueue();

    // Process the jobs in FIFO order
    spooler.processNextJob();
    spooler.processNextJob();

    cout << "\n";
    spooler.displayQueue();

    return 0;
}

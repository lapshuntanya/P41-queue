#include "myQueue.h"
#include <string>
using namespace std;

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.
    myQueue::Queue<string> p41;
    p41.push_back("Artemov");
    p41.push_back("But");
    p41.push_back("Karpenko");
    p41.push_back("Kuznetsov");
    p41.push_back("Nikitenko");
    p41.push_back("Ponomarenko");
    p41.push_back("Svechkarev");
    p41.push_back("Tronevych");

    p41.show();

    cout << "==========================\n";

    while (!p41.isEmpty()) {
        cout << "First: " << p41.first() << endl;
        p41.show();
        cout << endl;
        p41.pop_front();
    }

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}
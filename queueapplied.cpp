// Copyright [2026] <Rodrigo Stefanes>


// Removes the k-th vehicle from the queue. Vehicles in front must rotate to the end of the line.
void retira_veiculo(structures::ArrayQueue<int> *f, int k) {
    int i = 0;
    while (i < (k-1)) {
        (*f).enqueue((*f).dequeue());
        i = i + 1;
    }
    (*f).dequeue();
}

// Clears the queue, keeping only the k-th vehicle and removing all others.
void mantenha_veiculo(structures::ArrayQueue<int> *f, int k) {
    int i = 0;
    int j = (*f).size();
    while (i < k - 1) {
        (*f).dequeue();
        i = i + 1;
    }
    (*f).enqueue((*f).dequeue());
    i = i + 1;
    while (i < j) {
        (*f).dequeue();
        i = i + 1;
    }
}


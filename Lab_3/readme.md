1.a. Clone the repository to your local machine: 
```bash
git clone https://github.com/RauniMF13/Rauni_CSE3150.git
```
1.b. If you previously cloned the repo, pull the changes:
```bash
git pull
```
2. If you haven't already, clone the doctest repo and place it in the same directory as the Rauni_CSE3150 folder:
```bash
git clone https://github.com/doctest/doctest.git
```
3. Change directory to Lab_3:
```bash
cd Rauni_CSE3150/Lab_3
```
4. Compile the unit tests.
```bash
g++ -o test unit_tests_neg_prefix.cpp neg_prefix_min.cpp ../Week_3/lab_week2.cpp
```
5. Run the tests.
```bash
./test
```

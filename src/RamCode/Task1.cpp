#include "task1.h"

void Task1::runTask1(const string filename, int n)
{
    DataSet data;
    data.read_from_csv(filename, n);

    Matrix mdata(data.no_of_records(),data.get_data_set()[0].get_record().size());
    mdata.convert_from_dataset(data);
    vector< vector<double> > matrix = mdata.get_matrix();

    Matrix cosim(data.no_of_records(), data.no_of_records());
    vector< vector<double> > cosinesim = cosim.get_matrix();

    int size = data.no_of_records();
    
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            cosinesim[i][j] = cosineSimilarity(matrix[i], matrix[j]);
        }
    }

    
}
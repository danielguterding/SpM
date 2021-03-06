//=============================================================================
/*! dgbmatrix constructor */
inline dgbmatrix::dgbmatrix()
{CPPL_VERBOSE_REPORT;
  //////// initialize ////////
  m =0;
  n =0;
  kl=0;
  ku=0;
  array =NULL;
  darray =NULL;
}

//=============================================================================
/*! dgbmatrix copy constructor */
inline dgbmatrix::dgbmatrix(const dgbmatrix& mat)
{CPPL_VERBOSE_REPORT;
  //////// initialize ////////
  m =mat.m;
  n =mat.n;
  kl=mat.kl;
  ku=mat.ku;
  array =new double[(kl+ku+1)*n];
  darray =new double*[n];
  for(int i=0; i<n; i++){
    darray[i] =&array[i*(kl+ku+1)];
  }
  
  //////// copy ////////
  CPPL_INT size =(kl+ku+1)*n;
  CPPL_INT inc =1;
  dcopy_(&size, mat.array, &inc, array, &inc);
}

//=============================================================================
/*! dgbmatrix constructor to cast _dgbmatrix */
inline dgbmatrix::dgbmatrix(const _dgbmatrix& mat)
{CPPL_VERBOSE_REPORT;
  m =mat.m;
  n =mat.n;
  kl =mat.kl;
  ku =mat.ku;
  array =mat.array;
  darray =mat.darray;
  
  mat.nullify();
}

//=============================================================================
/*! dgbmatrix constructor with size specification */
inline dgbmatrix::dgbmatrix(const CPPL_INT& _m, const CPPL_INT& _n,
                            const CPPL_INT& _kl, const CPPL_INT& _ku)
{CPPL_VERBOSE_REPORT;
#ifdef  CPPL_DEBUG
  if( _m<0 || _n<0 || _kl<0 || _ku<0 || _m<_kl || _n<_ku ){
    ERROR_REPORT;
    std::cerr << "It is impossible to make a matrix you ordered. " << std::endl
              << "Your input was (" << _m << "," << _n << ","<< _ku << "," << _kl << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG
  
  //////// initialize ////////
  m =_m;
  n =_n;
  kl =_kl;
  ku =_ku;
  array =new double[(kl+ku+1)*n];
  darray =new double*[n];
  for(int i=0; i<n; i++){
    darray[i] =&array[i*(kl+ku+1)];
  }
}

//=============================================================================
/*! dgbmatrix constructor with filename */
inline dgbmatrix::dgbmatrix(const char* filename)
{CPPL_VERBOSE_REPORT;
  array =NULL;
  darray =NULL;
  
  //// read ////
  read(filename);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

//=============================================================================
/*! dgbmatrix destructor */
inline dgbmatrix::~dgbmatrix()
{CPPL_VERBOSE_REPORT;
  //////// delete array ////////
  delete [] array;
  delete [] darray;
}

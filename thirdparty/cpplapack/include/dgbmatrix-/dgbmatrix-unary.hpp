//=============================================================================
/*! +dgbmatrix operator */
inline const dgbmatrix& operator+(const dgbmatrix& mat)
{CPPL_VERBOSE_REPORT;
  return mat;
}

//=============================================================================
/*! -dgbmatrix operator */
inline _dgbmatrix operator-(const dgbmatrix& mat)
{CPPL_VERBOSE_REPORT;
  dgbmatrix newmat(mat.m,mat.n,mat.kl,mat.ku);
  for(CPPL_INT i=0; i<(newmat.kl+newmat.ku+1)*newmat.n; i++){
    newmat.array[i]=-mat.array[i];
  }
  
  return _(newmat);
}

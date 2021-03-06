//=============================================================================
/*! _zrovector*zgsmatrix operator */
inline _zrovector operator*(const _zrovector& vec, const zgsmatrix& mat)
{CPPL_VERBOSE_REPORT;
#ifdef  CPPL_DEBUG
  if(vec.l!=mat.m){
    ERROR_REPORT;
    std::cerr << "These vector and matrix can not make a product." << std::endl
              << "Your input was (" << vec.l << ") * (" << mat.m << "x" << mat.n << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG
  
  zrovector newvec(mat.n);
  newvec.zero();
  
  const std::vector<zcomponent>::const_iterator mat_data_end =mat.data.end();
  for(std::vector<zcomponent>::const_iterator it=mat.data.begin(); it!=mat_data_end; it++){
    newvec(it->j) += vec(it->i)*it->v;
  }
  
  vec.destroy();
  return _(newvec);
}

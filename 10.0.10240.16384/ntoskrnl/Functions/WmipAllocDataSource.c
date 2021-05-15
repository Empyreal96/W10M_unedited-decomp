// WmipAllocDataSource 
 
_DWORD *WmipAllocDataSource()
{
  _DWORD *result; // r0

  result = WmipAllocEntry((int *)&WmipDSChunkInfo);
  if ( result )
  {
    result[5] = result + 5;
    result[6] = result + 5;
    result[9] = 4;
    result[10] = result + 11;
    result[11] = 0;
    result[12] = 0;
    result[13] = 0;
    result[14] = 0;
  }
  return result;
}

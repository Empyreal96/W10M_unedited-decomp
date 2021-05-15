// CmpValidateGlobalFlushControlFlags 
 
int __fastcall CmpValidateGlobalFlushControlFlags(int result, int a2)
{
  if ( (CmpGlobalFlushControlFlags & 0xFFFFFFFE) != 0 )
    result = sub_81CD44(result, a2, &CmpGlobalFlushControlFlags, CmpGlobalFlushControlFlags & 0xFFFFFFFE);
  return result;
}

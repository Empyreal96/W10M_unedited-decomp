// MI_SET_PAGING_FILE_INFO 
 
int *__fastcall MI_SET_PAGING_FILE_INFO(int *result, _DWORD *a2, int a3, int a4, char a5)
{
  __int16 v5; // r2
  int v6; // r3

  v5 = *(_WORD *)(a3 + 96);
  *result = 0;
  v6 = *a2 & 0x3E0 | (4 * (v5 & 1 | (a4 << 11)));
  *result = v6;
  if ( (a5 & 1) != 0 )
    *result = v6 | 0x10;
  if ( (a5 & 2) != 0 )
    result = (int *)sub_548F78();
  return result;
}

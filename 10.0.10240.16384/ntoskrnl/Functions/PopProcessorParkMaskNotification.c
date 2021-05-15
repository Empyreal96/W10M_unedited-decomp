// PopProcessorParkMaskNotification 
 
int __fastcall PopProcessorParkMaskNotification(int a1, unsigned int *a2)
{
  __int64 v2; // kr00_8
  unsigned int i; // r5
  int result; // r0

  v2 = *(_QWORD *)(a1 + 36);
  if ( !(_DWORD)v2 || !*(_DWORD *)(v2 + 68) )
    return -1073741822;
  for ( i = 0; i < *a2; ++i )
    *(_DWORD *)(a2[4] + 8 * i) = *(_DWORD *)(*(_DWORD *)(a2[4] + 8 * i) + 40);
  if ( (*(int (__fastcall **)(_DWORD, int, unsigned int *))(v2 + 68))(HIDWORD(v2), 32, a2) )
    result = 0;
  else
    result = -1073741637;
  return result;
}

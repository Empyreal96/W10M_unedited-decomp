// PopProcessorParkNotification 
 
int __fastcall PopProcessorParkNotification(int a1, int a2)
{
  __int64 v2; // kr00_8
  unsigned int i; // r0
  int result; // r0

  v2 = *(_QWORD *)(a1 + 36);
  if ( !(_DWORD)v2 || !*(_DWORD *)(v2 + 68) )
    return -1073741822;
  for ( i = 0; i < *(_DWORD *)(a2 + 4); ++i )
    *(_DWORD *)(*(_DWORD *)(a2 + 8) + 8 * i) = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 8) + 8 * i) + 40);
  if ( !PopFxParkingFallback )
  {
    if ( (*(int (__fastcall **)(_DWORD, int, int))(v2 + 68))(HIDWORD(v2), 31, a2) )
      return sub_51EB6C();
    PopFxParkingFallback = 1;
  }
  if ( (*(int (__fastcall **)(_DWORD, int, int))(v2 + 68))(HIDWORD(v2), 14, a2) )
    result = 0;
  else
    result = -1073741637;
  return result;
}

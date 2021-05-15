// PopProcessorIdleSelectNotification 
 
int __fastcall PopProcessorIdleSelectNotification(int a1, _DWORD *a2)
{
  __int64 v2; // kr00_8
  unsigned int v4; // r5
  int v5; // r7
  unsigned int v6; // r2
  unsigned int v7; // r1

  v2 = *(_QWORD *)(a1 + 36);
  if ( !(_DWORD)v2 || !*(_DWORD *)(v2 + 68) )
    return -1073741822;
  v5 = a2[5];
  v4 = a2[4];
  if ( !((int (__fastcall *)(_DWORD, int, _DWORD *))v2)(HIDWORD(v2), 3, a2) )
    return -1073741637;
  v6 = a2[3];
  if ( v6 > v4 )
    sub_51C82C();
  v7 = 0;
  if ( !v6 )
    return 0;
  do
  {
    if ( !*(_DWORD *)v5 )
      JUMPOUT(0x51C83A);
    ++v7;
    *(_DWORD *)v5 = *(_DWORD *)(*(_DWORD *)v5 + 88);
    v5 += 8;
  }
  while ( v7 < v6 );
  return 0;
}

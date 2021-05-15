// EtwpClearSessionAndUnreferenceEntry 
 
int __fastcall EtwpClearSessionAndUnreferenceEntry(int a1, _DWORD *a2)
{
  int v4; // r9
  _DWORD *i; // r2
  int v7; // r0
  int v8; // r6
  int v9; // lr
  int v10; // r10
  unsigned int v11; // r1
  int v12; // r4
  int v13; // r5
  _DWORD *v14; // r2
  unsigned int v15; // r3
  int v16; // r3
  int v17[8]; // [sp+38h] [bp-40h] BYREF

  KeWaitForSingleObject((unsigned int)&EtwpNotificationMutex, 0, 0, 0, 0);
  if ( *((unsigned __int16 *)a2 + 24) == a1 )
  {
    a2[10] = 0;
    a2[11] = 0;
    a2[12] = 0;
    a2[13] = 0;
  }
  v4 = 0;
  for ( i = a2 + 22; *i != 1 || *((unsigned __int16 *)i + 3) != a1; i += 8 )
  {
    if ( (unsigned int)++v4 >= 8 )
    {
      KeReleaseMutex((int)&EtwpNotificationMutex);
      return 0;
    }
  }
  *i = 0;
  memset(v17, 0, sizeof(v17));
  v7 = -1;
  v9 = v17[4];
  v8 = v17[5];
  v10 = v17[2];
  v11 = LOBYTE(v17[1]);
  v12 = 8;
  v17[6] = -1;
  v17[7] = -1;
  v13 = -1;
  v14 = a2;
  do
  {
    if ( v14[22] )
    {
      v15 = *((unsigned __int8 *)v14 + 92);
      v17[0] = 1;
      if ( v11 <= v15 )
        LOBYTE(v11) = v15;
      v16 = v14[26];
      v11 = (unsigned __int8)v11;
      LOBYTE(v17[1]) = v11;
      v9 |= v16;
      v8 |= v14[27];
      v7 &= v14[28];
      v13 &= v14[29];
      v10 |= v14[24];
    }
    v14 += 8;
    --v12;
  }
  while ( v12 );
  return sub_7EE26C();
}

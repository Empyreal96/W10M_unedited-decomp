// IoWMIAllocateInstanceIds 
 
int __fastcall IoWMIAllocateInstanceIds(_DWORD *a1, int a2, _DWORD *a3)
{
  _DWORD *v3; // r6
  _DWORD *v8; // r5
  unsigned int v9; // r6
  _DWORD *v10; // r4
  _BYTE *v11; // r0
  _DWORD *v12; // r4
  int v13; // r1
  int v14; // r2
  int v15; // r3

  v3 = 0;
  if ( !WmipServiceDeviceObject )
    return -1073741823;
  KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
  v8 = (_DWORD *)WmipInstIdChunkHead;
LABEL_9:
  if ( v8 )
  {
    v9 = 0;
    v10 = v8 + 1;
    while ( v10[4] != -1 )
    {
      if ( !memcmp((unsigned int)a1, (unsigned int)v10, 16) )
      {
        *a3 = v10[4];
        v10[4] += a2;
        KeReleaseMutex((int)&WmipSMMutex);
        return 0;
      }
      ++v9;
      v10 += 5;
      if ( v9 >= 8 )
      {
        v3 = v8;
        v8 = (_DWORD *)*v8;
        goto LABEL_9;
      }
    }
  }
  else
  {
    v11 = (_BYTE *)ExAllocatePoolWithTag(1, 164, 1768516951);
    v12 = v11;
    if ( !v11 )
    {
      KeReleaseMutex((int)&WmipSMMutex);
      return -1073741670;
    }
    memset(v11, 255, 164);
    *v12 = 0;
    if ( v3 )
      *v3 = v12;
    else
      WmipInstIdChunkHead = (int)v12;
    v10 = v12 + 1;
  }
  v13 = a1[1];
  v14 = a1[2];
  v15 = a1[3];
  *v10 = *a1;
  v10[1] = v13;
  v10[2] = v14;
  v10[3] = v15;
  v10[4] = a2;
  KeReleaseMutex((int)&WmipSMMutex);
  *a3 = 0;
  return 0;
}

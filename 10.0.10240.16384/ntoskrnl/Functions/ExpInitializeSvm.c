// ExpInitializeSvm 
 
char *__fastcall ExpInitializeSvm(int a1, int a2, int a3, unsigned int a4)
{
  int v4; // r0
  int v5; // r3
  char *result; // r0
  unsigned int v7; // r5
  int v8; // r6
  char *v9; // r2
  void **v10; // r2
  unsigned int v11[6]; // [sp+0h] [bp-18h] BYREF

  v11[0] = a4;
  v4 = ((int (__fastcall *)(_DWORD, unsigned int *, int *, int *))HalIommuDispatch[1])(
         0,
         v11,
         &ExpSvmAgents,
         &ExpSvmIommuSystemContext);
  v5 = v11[0];
  if ( v11[0] > 1 )
    return (char *)sub_96C578(v4);
  result = (char *)ExpSvmWorkQueues;
  if ( !ExpSvmWorkQueues || v11[0] == 1 )
  {
    result = (char *)&ExpSvmStaticWorkQueue;
    v5 = 1;
    ExpSvmWorkQueues = (int)&ExpSvmStaticWorkQueue;
  }
  v7 = 0;
  ExpSvmNumberOfWorkQueues = v5;
  if ( v5 )
  {
    v8 = 0;
    while ( 1 )
    {
      v9 = &result[v8];
      *((_DWORD *)v9 + 2) = ExpSvmWorkerThread;
      *((_DWORD *)v9 + 3) = v7;
      *(_DWORD *)&result[v8] = 0;
      v9[16] = 19;
      v9[17] = 1;
      *((_WORD *)v9 + 9) = 0;
      *((_DWORD *)v9 + 7) = ExpSvmDpcRoutine;
      *((_DWORD *)v9 + 8) = v7;
      *((_DWORD *)v9 + 11) = 0;
      *((_DWORD *)v9 + 6) = 0;
      __dmb(0xBu);
      ++v7;
      v8 += 52;
      *((_DWORD *)v9 + 12) = 0;
      if ( v7 >= ExpSvmNumberOfWorkQueues )
        break;
      result = (char *)ExpSvmWorkQueues;
    }
  }
  v10 = HalIommuDispatch;
  HalIommuDispatch[12] = ExpSvmFaultRoutine;
  v10[13] = ExpSvmReferenceAsid;
  v10[14] = ExpSvmDereferenceAsid;
  v10[15] = ExpSvmServicePageFault;
  dword_619EF0 = 0;
  ExpSvmDeviceListLock = 0;
  ExpSvmDevices = (int)&ExpSvmDevices;
  *(_DWORD *)algn_619F04 = &ExpSvmDevices;
  return result;
}

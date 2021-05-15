// EtwpServerSiloCreateNotify 
 
int __fastcall EtwpServerSiloCreateNotify(int a1, int a2, int a3, _BYTE *a4)
{
  int v5; // r4
  _BYTE *v6; // r7
  BOOL v7; // r0
  BOOL v8; // r9
  int v10; // r5
  unsigned int v11; // r1
  int v12; // r0
  __int16 v13; // r2
  _BYTE *v14; // r3
  _BYTE *v15; // [sp+8h] [bp-20h] BYREF

  v15 = a4;
  v5 = PsAllocateMonitorContextServerSilo(EtwSiloMonitor, 400, &v15);
  if ( v5 >= 0 )
  {
    v6 = v15;
    memset(v15, 0, 400);
    v7 = PsIsHostSilo(a1);
    v8 = v7;
    *((_DWORD *)v6 + 5) = 1417975333;
    *((_DWORD *)v6 + 6) = 1234457720;
    *((_DWORD *)v6 + 7) = 993966757;
    *((_DWORD *)v6 + 8) = 230893571;
    *((_DWORD *)v6 + 89) = a1;
    if ( a1 )
      return sub_810C1C();
    if ( v7 )
    {
      *((_WORD *)v6 + 51) = 3;
      *((_WORD *)v6 + 188) = 3;
    }
    else
    {
      *((_WORD *)v6 + 51) = 64;
    }
    *((_DWORD *)v6 + 90) = *((unsigned __int16 *)v6 + 51);
    v5 = PsSetMonitorContextServerSilo(EtwSiloMonitor, 0, 1, (int)v6, 0);
    if ( v5 >= 0 )
    {
      v10 = PsAttachSiloToCurrentThread(0);
      EtwpInitializeAutoLoggers();
      if ( !v8 )
        EtwRegister((int)PsProvGuid, 0, 0);
      PsDetachSiloFromCurrentThread(v10);
      v11 = 0;
      v12 = 96;
      do
      {
        v13 = *(_WORD *)&v6[2 * v11 + 376];
        if ( v13 )
        {
          v14 = &v6[v12];
          *((_WORD *)v14 + 3) = v13;
          v14[4] = -1;
          *((_DWORD *)v14 + 4) = -1;
          *((_DWORD *)v14 + 5) = -1;
          *((_DWORD *)v14 + 6) = 0;
          *((_DWORD *)v14 + 7) = 0;
          *((_DWORD *)v14 + 2) = 64;
          *(_DWORD *)&v6[v12] = 1;
          v6[392] |= 1 << v11;
        }
        ++v11;
        v12 += 32;
      }
      while ( v11 < 8 );
      PsDereferenceMonitorContextServerSilo((int)v6);
    }
  }
  return v5;
}

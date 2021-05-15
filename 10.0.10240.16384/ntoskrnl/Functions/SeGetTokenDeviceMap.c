// SeGetTokenDeviceMap 
 
int __fastcall SeGetTokenDeviceMap(_DWORD *a1, _DWORD *a2)
{
  int v4; // r5
  int v5; // r3
  int v6; // r4
  _DWORD *v8; // r0
  unsigned int *v9; // r2
  unsigned int v10; // r0
  unsigned int v11; // r1
  int v12; // [sp+8h] [bp-C8h]
  unsigned int v13; // [sp+Ch] [bp-C4h] BYREF
  int v14; // [sp+10h] [bp-C0h]
  int v15; // [sp+14h] [bp-BCh]
  char *v16; // [sp+18h] [bp-B8h]
  int v17; // [sp+1Ch] [bp-B4h]
  int v18; // [sp+20h] [bp-B0h]
  int v19; // [sp+24h] [bp-ACh]
  char v20[8]; // [sp+28h] [bp-A8h] BYREF
  char v21[8]; // [sp+38h] [bp-98h] BYREF
  unsigned __int16 v22[72]; // [sp+40h] [bp-90h] BYREF

  v13 = 0;
  if ( !a1 || !a2 )
    return -1073741811;
  if ( (a1[44] & 0x20) == 0 )
  {
    v4 = a1[48];
    if ( v4 )
    {
      v5 = *(_DWORD *)(v4 + 28);
      if ( v5 )
      {
        *a2 = v5;
        v6 = 0;
      }
      else
      {
        v8 = PsGetServerSiloGlobals(*(_DWORD *)(v4 + 88));
        swprintf_s((int)v22, 64, (int)L"\\Sessions\\%d\\DosDevices\\%08x-%08x", *v8, a1[7], a1[6]);
        RtlInitUnicodeString((unsigned int)v20, v22);
        v14 = 24;
        v15 = 0;
        v17 = 704;
        v16 = v20;
        v18 = 0;
        v19 = 0;
        v6 = ZwCreateDirectoryObject();
        if ( v6 >= 0 )
        {
          v6 = ((int (__fastcall *)(unsigned int *))ObSetDirectoryDeviceMap)(&v13);
          if ( v6 >= 0 )
          {
            RtlInitUnicodeString((unsigned int)v21, L"Global");
            RtlInitUnicodeString((unsigned int)v20, L"\\Global??");
            v14 = 24;
            v15 = v12;
            v17 = 720;
            v16 = v21;
            v18 = 0;
            v19 = 0;
            v6 = ZwCreateSymbolicLinkObject();
            if ( v6 < 0 )
            {
              ObfDereferenceDeviceMap(v13);
            }
            else
            {
              ZwClose();
              __dmb(0xBu);
              v9 = (unsigned int *)(v4 + 28);
              v10 = v13;
              do
                v11 = __ldrex(v9);
              while ( !v11 && __strex(v10, v9) );
              __dmb(0xBu);
              if ( v11 )
                ObfDereferenceDeviceMap(v10);
              *a2 = *(_DWORD *)(v4 + 28);
            }
          }
          ZwClose();
        }
      }
      return v6;
    }
  }
  return sub_7C4038();
}

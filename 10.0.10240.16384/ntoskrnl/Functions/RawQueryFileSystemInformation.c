// RawQueryFileSystemInformation 
 
int __fastcall RawQueryFileSystemInformation(int a1, int a2, int a3)
{
  unsigned int v6; // r2
  _DWORD *v7; // r7
  int v8; // r4
  _BYTE *v9; // r0
  unsigned int v10; // r6
  _BYTE *v11; // r0
  unsigned int v12; // r5
  _DWORD *v13; // r0
  unsigned int v14; // r3
  int v16[2]; // [sp+18h] [bp-50h] BYREF
  _DWORD v17[5]; // [sp+20h] [bp-48h] BYREF
  int v18[5]; // [sp+34h] [bp-34h] BYREF

  __dmb(0xBu);
  v17[0] = 0;
  v17[1] = 0;
  v17[2] = 0;
  v17[3] = 0;
  v16[0] = 0;
  v16[1] = 0;
  v17[4] = 0;
  memset(v18, 0, sizeof(v18));
  v6 = *(_DWORD *)(a2 + 8);
  v7 = *(_DWORD **)(a1 + 12);
  if ( v6 < 9 )
    return -1073741789;
  v9 = memset(*(_BYTE **)(a1 + 12), 0, v6);
  v8 = RawPerformDevIoCtrl(v9, *(_DWORD *)(a3 + 136));
  if ( v8 >= 0 )
  {
    v10 = v18[4];
    if ( v18[4] >= 0x18u )
    {
      v11 = (_BYTE *)ExAllocatePoolWithTag(1, v18[4], 1649885522);
      v12 = (unsigned int)v11;
      if ( v11 )
      {
        memset(v11, 0, v10);
        KeInitializeEvent((int)v17, 0, 0);
        v13 = IoBuildSynchronousFsdRequest(3, *(_DWORD *)(a3 + 136), v12, v10, 0, (int)v17, (int)v16);
        if ( v13 )
        {
          *(_BYTE *)(v13[24] - 38) |= 2u;
          v8 = IofCallDriver(*(_DWORD *)(a3 + 136), (int)v13);
          if ( v8 == 259 )
          {
            KeWaitForSingleObject((unsigned int)v17, 0, 0, 0, 0);
            v8 = v16[0];
          }
          if ( v8 >= 0 )
          {
            if ( *(_DWORD *)(v12 + 16) == 1397904198
              && (v14 = *(unsigned __int16 *)(v12 + 20), v14 <= v10)
              && v14 >= 0x18
              && RawComputeFileSystemInformationChecksum(v12) == *(unsigned __int16 *)(v12 + 22) )
            {
              *v7 = *(_DWORD *)(v12 + 3);
              v7[1] = *(_DWORD *)(v12 + 7);
              *(_DWORD *)(a1 + 28) = 9;
            }
            else
            {
              v8 = -1073741637;
            }
          }
        }
        else
        {
          v8 = -1073741670;
        }
        ExFreePoolWithTag(v12);
      }
      else
      {
        v8 = -1073741670;
      }
    }
    else
    {
      v8 = -1073741637;
    }
  }
  return v8;
}

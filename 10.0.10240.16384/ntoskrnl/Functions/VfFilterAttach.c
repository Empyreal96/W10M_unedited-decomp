// VfFilterAttach 
 
int __fastcall VfFilterAttach(int result, int a2)
{
  int v3; // r6
  int v4; // r5
  _DWORD *v5; // r4
  int *v6; // r5
  int v7; // r0
  unsigned int *v8; // r2
  int v9[6]; // [sp+10h] [bp-18h] BYREF

  v3 = result;
  if ( !VfFilterCreated )
  {
    RtlInitUnicodeString((unsigned int)v9, L"\\DRIVER\\VERIFIER_FILTER");
    result = IoCreateDriver(v9, (int (__fastcall *)(_BYTE *, _DWORD))ViFilterDriverEntry);
    VfFilterCreated = 1;
  }
  v4 = VfFilterDriverObject;
  if ( VfFilterDriverObject && a2 >= 2 && (a2 <= 3 || (unsigned int)(a2 - 5) <= 1) )
  {
    result = IoGetAttachedDevice(v3);
    if ( *(_DWORD *)(result + 8) != v4 )
    {
      result = IoCreateDevice(v4, 68, 0, 0x22u, 256, 0, v9);
      if ( result >= 0 )
      {
        v5 = (_DWORD *)v9[0];
        v6 = *(int **)(v9[0] + 40);
        IoInitializeRemoveLockEx((int)(v6 + 4), 1280468566, 0, 0, 24);
        v6[14] = 0;
        v7 = IoAttachDeviceToDeviceStack((int)v5, v3);
        v6[1] = v7;
        if ( v7 )
        {
          v5[7] |= *(_DWORD *)(v7 + 28) & 0x86014;
          v5[11] = *(_DWORD *)(v6[1] + 44);
          v5[8] = *(_DWORD *)(v6[1] + 32);
          v5[7] &= 0xFFFFFF7F;
          v6[2] = (int)v5;
          *v6 = v3;
          __dmb(0xBu);
          v8 = (unsigned int *)(v6 + 16);
          do
            result = __ldrex(v8);
          while ( __strex(result | 1, v8) );
          __dmb(0xBu);
        }
        else
        {
          result = IoDeleteDevice(v5);
        }
      }
    }
  }
  return result;
}

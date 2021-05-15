// PoFxRegisterDebugger 
 
_BYTE *PoFxRegisterDebugger()
{
  _BYTE *result; // r0
  unsigned int v1; // r6
  _DWORD *v2; // r5
  unsigned __int16 *v3; // r4
  int v4; // r7
  int v5; // r8
  int *v6; // r2
  int v7; // r3
  unsigned int *v8; // r6
  int v9; // r2
  unsigned int v10; // [sp+Ch] [bp-B8h] BYREF
  int *v11; // [sp+10h] [bp-B4h] BYREF
  int v12; // [sp+14h] [bp-B0h] BYREF
  char v13[8]; // [sp+1Ch] [bp-A8h] BYREF
  _DWORD v14[14]; // [sp+24h] [bp-A0h] BYREF
  char v15[104]; // [sp+5Ch] [bp-68h] BYREF

  result = (_BYTE *)off_617B54(33, 0, 0, &v10);
  if ( result == (_BYTE *)-2147483643 )
  {
    v1 = v10;
    result = (_BYTE *)ExAllocatePoolWithTag(512, v10, 1297630800);
    v2 = result;
    if ( result )
    {
      memset(result, 0, v1);
      if ( ((int (__cdecl *)())off_617B54)() >= 0
        && v10 <= v1
        && (v3 = (unsigned __int16 *)(v2 + 1), v4 = 0, v5 = 0, *v2) )
      {
        while ( 1 )
        {
          v3 = (unsigned __int16 *)((char *)v3 + v5);
          v5 = *((_DWORD *)v3 + 1);
          if ( *(_DWORD *)v3 != 1 || !*((_DWORD *)v3 + 2) )
            break;
          RtlInitUnicodeString((unsigned int)v13, v3 + 6);
          memset(v15, 0, 24);
          memset(v14, 0, sizeof(v14));
          v14[0] = 1;
          v14[1] = 1;
          v14[11] = 1;
          v14[13] = v15;
          v14[4] = PopFxDebuggerPowerCriticalTransitionCallback;
          if ( PoFxRegisterCoreDevice((int)v13, v14, &v11) >= 0 )
          {
            v6 = v11;
            v7 = v11[96] | 2;
            __dmb(0xBu);
            v6[96] = v7;
            v8 = (unsigned int *)v11;
            v9 = v11[9];
            if ( v9 )
            {
              v12 = v11[10];
              (*(void (__fastcall **)(int, int *))(v9 + 64))(21, &v12);
            }
            PoFxActivateComponent(v8, 0, 1);
            PoFxStartDevicePowerManagement((int)v8);
            if ( (unsigned int)++v4 < *v2 )
              continue;
          }
          goto LABEL_13;
        }
        result = (_BYTE *)sub_96D60C();
      }
      else
      {
LABEL_13:
        result = (_BYTE *)ExFreePoolWithTag((unsigned int)v2);
      }
    }
  }
  return result;
}

// PopLogNotifyDevice 
 
int *__fastcall PopLogNotifyDevice(int *result, int a2, int a3)
{
  int v3; // r3
  int v4; // r4
  unsigned __int16 *v5; // r5
  unsigned int v6; // r0
  int v7; // r4
  int v8[2]; // [sp+8h] [bp-120h] BYREF
  char v9; // [sp+10h] [bp-118h]
  char v10; // [sp+11h] [bp-117h]
  char v11; // [sp+12h] [bp-116h]
  int v12; // [sp+14h] [bp-114h]
  int v13; // [sp+18h] [bp-110h]
  __int16 v14[116]; // [sp+20h] [bp-108h] BYREF
  int v15[8]; // [sp+108h] [bp-20h] BYREF

  if ( (dword_682610 & 0x8000) != 0 )
  {
    v3 = result[2];
    v4 = *(_DWORD *)(a3 + 96);
    v8[0] = a3;
    v8[1] = *(_DWORD *)(v3 + 12);
    v10 = *(_BYTE *)(v4 - 40);
    v11 = *(_BYTE *)(v4 - 39);
    v12 = *(_DWORD *)(v4 - 28);
    v13 = *(_DWORD *)(v4 - 24);
    if ( a2 )
    {
      v5 = *(unsigned __int16 **)(a2 + 36);
      v9 = *(_BYTE *)(a2 + 28);
      if ( v5 )
      {
        v6 = wcslen(v5);
        v7 = v6;
        if ( v6 > 0x72 )
          v7 = 114;
        RtlStringCchCopyW(v14, 0x73u, (int)&v5[v6 - v7]);
        goto LABEL_9;
      }
    }
    else
    {
      v9 = 0;
    }
    v7 = 0;
    v14[0] = 0;
LABEL_9:
    v15[0] = (int)v8;
    v15[1] = 0;
    v15[2] = 2 * (v7 + 14);
    v15[3] = 0;
    result = EtwTraceKernelEvent(v15, 1, 0x80008000, 4646, 4200450);
  }
  return result;
}

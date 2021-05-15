// PopHiberCheckResume 
 
int PopHiberCheckResume()
{
  int v0; // r5
  _DWORD *v1; // r6
  int v3; // r0
  int v4; // r1
  int v5; // r7
  int v6; // r8
  int v7; // r2
  int v8; // r1
  int v9; // r4
  int v10; // r3
  _BYTE *v11; // r3
  int v12; // [sp+0h] [bp-C0h] BYREF
  __int16 v13; // [sp+4h] [bp-BCh]
  __int16 v14; // [sp+6h] [bp-BAh]
  int v15; // [sp+10h] [bp-B0h]
  int v16; // [sp+14h] [bp-ACh]
  int v17; // [sp+18h] [bp-A8h]
  int v18; // [sp+1Ch] [bp-A4h]
  int v19; // [sp+20h] [bp-A0h]
  int v20; // [sp+24h] [bp-9Ch]
  int v21; // [sp+28h] [bp-98h]

  v0 = dword_61EC98;
  v1 = *(_DWORD **)(dword_61EC98 + 128);
  if ( !*v1 )
    return 0;
  off_617AC4(0);
  v3 = ReadTimeStampCounter();
  v5 = v4;
  v6 = v3;
  if ( *(_BYTE *)(v0 + 3) )
    *(_BYTE *)(v0 + 4) = 1;
  PoResumeFromHibernate = 1;
  ((void (__cdecl *)())off_617A08)();
  ((void (__cdecl *)())off_617AC4)();
  ((void (__cdecl *)())off_617A88)();
  v7 = (unsigned __int8)KdDebuggerEnabled;
  if ( KdDebuggerEnabled && !KdPitchDebugger || KdEventLoggingEnabled )
  {
    KdDebuggerEnabled = 0;
    KdInitSystem(0, 0);
    v7 = (unsigned __int8)KdDebuggerEnabled;
  }
  if ( v7 && *v1 == 1347113538 )
    __debugbreak();
  if ( (PopSimulate & 0x40000000) != 0 )
    __debugbreak();
  HalInitializeOnResume(*(_DWORD *)(v0 + 144), *(_DWORD *)(v0 + 148));
  if ( v1[191] )
  {
    v12 = 0;
    v13 = 44;
    v14 = 0;
    v15 = 0;
    v17 = 0;
    v9 = 0x4000;
    v18 = v1[191];
    v10 = v1[192];
    v16 = 0x4000;
    v19 = v10;
    v20 = v1[193];
    v21 = v1[194];
    MmMapMemoryDumpMdlEx(*(_DWORD *)(*(_DWORD *)(v0 + 164) + 4), v8, (int)&v12, 1);
    v11 = *(_BYTE **)(*(_DWORD *)(v0 + 164) + 4);
    do
    {
      *v11++ = 0;
      --v9;
    }
    while ( v9 );
  }
  dword_61A1F8 = v1[186];
  dword_61A1FC = v1[187];
  memmove((int)&dword_61EFA0, (int)(v1 + 26), 0x1E0u);
  *(_DWORD *)(v0 + 140) = v1[148];
  __dmb(0xBu);
  *(_BYTE *)(v0 + 5) = 0;
  dword_61F068 = v6;
  dword_61F06C = v5;
  qword_61EFF8 = __PAIR64__(v5, v6) - qword_61F000;
  return 1;
}

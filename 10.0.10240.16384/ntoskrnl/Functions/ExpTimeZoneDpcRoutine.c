// ExpTimeZoneDpcRoutine 
 
int __fastcall ExpTimeZoneDpcRoutine(int result, int a2, int a3, int a4)
{
  unsigned int *v4; // r8
  char v5; // r6
  int v6; // lr
  unsigned int v7; // r2
  unsigned int v8; // r2
  unsigned int v9; // [sp+E1h] [bp-77h]
  unsigned int v10; // [sp+E5h] [bp-73h]
  unsigned __int64 v11; // [sp+119h] [bp-3Fh]
  char v12; // [sp+129h] [bp-2Fh]

  v4 = (unsigned int *)a2;
  if ( (a2 & 3) != 0 )
  {
    *(_BYTE *)result = 0;
    *(_DWORD *)(result + 16) = (unsigned __int64)a4 >> 8;
    v12 = a3;
    v5 = 64 - (a3 & 0x3F);
    LODWORD(v11) = (a2 << (a3 & 0x3F)) | ((unsigned int)a2 >> v5) | (a2 >> 31 << ((a3 & 0x3F) - 32)) | ((unsigned int)(a2 >> 31) >> (32 - (a3 & 0x3F)));
    HIDWORD(v11) = (a2 << ((a3 & 0x3F) - 32)) | (a2 >> 31 << (a3 & 0x3F)) | ((unsigned int)a2 >> (32 - (a3 & 0x3F))) | ((unsigned int)(a2 >> 31) >> v5);
    v9 = ((unsigned __int64)result >> (a3 & 0x3F)) | (result << v5);
    v10 = ((unsigned int)(result >> 31) >> (a3 & 0x3F)) | (result >> 31 << v5) | ((unsigned int)result >> ((a3 & 0x3F) - 32)) | (result << (32 - (a3 & 0x3F)));
    *(_DWORD *)(result + 20) ^= a4;
    *(_DWORD *)(result + 24) ^= a3;
    KiCustomAccessRoutine8((unsigned int *)a2);
    v6 = (v9 >> (64 - (v12 & 0x3F))) | (v10 << ((v12 & 0x3F) - 32)) | (v10 >> (32 - (v12 & 0x3F))) | (v9 << (v12 & 0x3F));
    result = (HIDWORD(v11) << (64 - (v12 & 0x3F))) | ((unsigned int)v11 >> ((v12 & 0x3F) - 32)) | ((_DWORD)v11 << (32 - (v12 & 0x3F)));
    v4 = (unsigned int *)(((_DWORD)v11 << (64 - (v12 & 0x3F))) | (v11 >> (v12 & 0x3F)));
    *(_DWORD *)(v6 + 16) = v4;
    *(_BYTE *)v6 = 19;
  }
  __dmb(0xBu);
  do
  {
    v7 = __ldrex(v4);
    v8 = v7 + 1;
  }
  while ( __strex(v8, v4) );
  __dmb(0xBu);
  if ( v8 == 1 )
    result = ExQueueWorkItem(&ExpTimeZoneWorkItem, 1);
  return result;
}

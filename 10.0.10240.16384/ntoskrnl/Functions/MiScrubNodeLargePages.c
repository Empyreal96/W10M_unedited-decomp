// MiScrubNodeLargePages 
 
int __fastcall MiScrubNodeLargePages(int result, int a2, int a3)
{
  _DWORD *v3; // r5
  int v4; // r6
  _DWORD *v5; // r8
  int v6; // r5
  _DWORD *v7; // r9
  int v8; // r10
  _DWORD *v9; // r7
  int v10; // [sp+8h] [bp-30h]
  int v12; // [sp+10h] [bp-28h]
  int v13; // [sp+14h] [bp-24h]

  v12 = result;
  v3 = (_DWORD *)(dword_63F718 + 104 * a2);
  v13 = (int)v3;
  if ( v3[1] || *v3 )
  {
    result = MiAcquireNonPagedResources(MiSystemPartition, 0x400u);
    if ( result )
    {
      v10 = MiReservePtes(&dword_634D58, 0x400u);
      if ( v10 )
      {
        v4 = 0;
        v5 = v3 + 4;
LABEL_7:
        v6 = 1;
        v7 = v5;
LABEL_8:
        v8 = 0;
        v9 = v7;
        while ( (_DWORD *)*v9 == v9 || MiScrubNodeLargePageList(v13, v4, v6, v8, v12, a3) )
        {
          ++v8;
          v9 += 2;
          if ( v8 )
          {
            if ( v6 )
            {
              --v6;
              v7 -= 2;
              goto LABEL_8;
            }
            ++v4;
            v5 += 4;
            if ( v4 <= 1 )
              goto LABEL_7;
            break;
          }
        }
        MiReleaseNonPagedResources(MiSystemPartition, 1024);
        result = MiReleasePtes(&dword_634D58, v10, 0x400u);
      }
      else
      {
        result = MiReleaseNonPagedResources(MiSystemPartition, 1024);
      }
    }
  }
  return result;
}

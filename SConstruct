env = Environment(CCFLAGS = '-O2 -std=c99 -D_POSIX_C_SOURCE=200809L -Wall')

env.Library('error', ['error.c', 'error_str.c'])

env.Library('fs', [
    'fmt_str.c',
    'fmt_uint.c',
    'fmt_uint0.c',
    'fmt_ulong.c',
    'scan_ulong.c'
])

env.Library('open', ['open_read.c', 'open_trunc.c', 'open_write.c'])

env.Library('str', [
    'str_len.c',
    'str_diff.c',
    'byte_diff.c',
    'byte_chr.c',
    'byte_copy.c',
    'byte_cr.c',
    'byte_zero.c'
])

env.Library('strerr', ['strerr_sys.c', 'strerr_die.c'])

env.Library('substdio', [
    'substdio.c',
    'substdi.c',
    'substdo.c',
    'subfderr.c',
    'substdio_copy.c'
])

env.Library('tai', [
    'tai_pack.c', 'tai_unpack.c', 'taia_add.c', 'taia_half.c', 'taia_less.c',
    'taia_now.c', 'taia_pack.c', 'taia_sub.c', 'taia_unpack.c',
    'leapsecs_add.c', 'leapsecs_init.c', 'leapsecs_read.c'])

env.Object('ip.c')

env.Program('sntpclock', ['sntpclock.c', 'ip.o'],
    LIBS=['tai', 'strerr', 'substdio', 'error', 'str', 'fs'],
    LIBPATH='.')

env.Program('taiclock', ['taiclock.c', 'ip.o'],
    LIBS=['tai', 'strerr', 'substdio', 'error', 'str', 'fs'],
    LIBPATH='.')
    
env.Program('taiclockd', ['taiclockd.c'],
    LIBS=['tai', 'strerr', 'substdio', 'error', 'str'],
    LIBPATH='.')

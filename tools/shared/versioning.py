from subprocess import run

from shared.common import SRC_DIR


def get_branch_version(branch: str | None) -> str:
    return run(
        [
            "git",
            "describe",
            *([branch] if branch else ["--dirty"]),
            "--always",
            "--abbrev=7",
            "--tags",
            "--exclude",
            "latest",
        ],
        cwd=SRC_DIR,
        text=True,
        capture_output=True,
        check=False,
    ).stdout.strip()


def generate_version() -> str:
    version = get_branch_version(None)
    return f'TR2X {version or "?"}'
